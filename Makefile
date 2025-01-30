NAME = cub3D

SRCDIR = src
OBJDIR = obj
INCDIR = include

SRC = main.c \
\
		parsing/parsing.c \
			parsing/read_map.c \
			parsing/process/handler_process.c \
			parsing/process/process_data_texture.c \
			parsing/process/process_map.c \
\
			parsing/validate/handler_validate.c \
			parsing/validate/valid_carac.c \
			parsing/validate/valid_close_wall.c \
			parsing/validate/valid_data.c \
			parsing/validate/valid_player.c \
			parsing/validate/valid_door.c \
\
		exec/exec.c \
			exec/render/render_map_3d.c \
			exec/render/render_loop.c \
			exec/render/img_compression.c \
			exec/render/render_sprites.c \
			exec/render/render_anim_sprites.c \
\
			exec/mlx/mlx_init.c \
			exec/mlx/mlx_events.c \
			exec/mlx/ft_put_pixel_in_img.c \
			exec/mlx/ft_get_pixel_color.c \
			exec/mlx/mlx_load_textures.c \
			exec/mlx/valid_textures.c \
\
			exec/game/move_player.c \
			exec/game/action_door.c \
			exec/game/action_shoot.c \
			exec/game/sprint_player.c \
			exec/game/action_hands_fights.c \
\
			exec/hud/handler_hud.c \
			exec/hud/hud_mini_map.c \
			exec/hud/hud_weapon.c \
			exec/hud/hud_string.c \
			exec/hud/hud_stats_player.c \
			exec/hud/hud_menu.c \
			exec/hud/helper_mlx_put_hud_to_win.c \
			exec/hud/hud_bam_comics.c \
\
			exec/ray_casting/ray_casting.c \
			exec/ray_casting/ray_render.c \
			exec/ray_casting/ray_setter.c \
			exec/ray_casting/texture_setter.c \
\
			exec/sprites/sprite_get.c \
			exec/sprites/sprite_get_helper.c \
			exec/sprites/sprite_sort.c \
			exec/sprites/sprite_shot.c \
\
		utils/helper.c \
		utils/cleanup.c \
		utils/init_env.c \
		utils/ft_free.c \
		utils/ft_is_space.c \
		utils/ft_strclen.c \
		utils/is_map_line.c \
		utils/is_textures_line.c \
		utils/get_msg_error.c \
		utils/exit_by_user.c \
		utils/normalize_angle.c \
		utils/rgb_to_hex.c \
		utils/player_adjacent_door.c \
		utils/trigonometry.c \
		utils/ft_mlx_destroy_image.c \
\
		debug/debug_parsing.c


OBJ = $(SRC:.c=.o)
SRC := $(addprefix $(SRCDIR)/, $(SRC))
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))

BUILD = $(OBJDIR)/.build

# LIBFT
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
LIBFT_INCLUDE := $(LIBFT_DIR)/include
# LIBX
MINILIBX_DIR := ./minilibx-linux
MLX := $(MINILIBX_DIR)/libmlx.a
# LIBFLAGS
LDFLAGS =  -L$(MINILIBX_DIR) -L$(LIBFT_DIR)
LIBS = $(MLX) $(LIBFT)


CC = cc
COPTI =  -O3 -march=native -mtune=native -flto -funroll-loops -ffp-contract=fast -falign-functions=32 -fno-plt -fstack-protector-strong -D_FORTIFY_SOURCE=2 -pipe
CFLAGS = $(COPTI) -Wall -Werror -Wextra -I$(INCDIR) -g3 -I$(MINILIBX_DIR) -I/usr/include/X11 -I$(LIBFT_INCLUDE)
AR = ar
ARFLAGS = rcs


# LIBXFLAGS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLXFLAGS += -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S),Darwin)
	MLXFLAGS += -L/opt/X11/lib -lX11 -lXext -lXrandr -lXcursor
endif

#################################
#          COMPIL MODE          #
#################################
VERBOSE ?= 0
ifeq ($(VERBOSE),1)
  V := 
else
  V := @
endif

#################################
#             COLORS            #
#################################
RED     := "\033[1;31m"
GREEN   := "\033[1;32m"
RESET   := "\033[0m"

#################################
#            EXECUTABLE         #
#################################

all: $(NAME)

$(NAME): $(BUILD)

$(BUILD): $(MINILIBX_DIR) $(LIBFT) $(OBJ)
#@clear
	$(V)export DEBUG_MODE=0
	$(V)$(CC) $(CFLAGS) $(LDFLAGS) $(OBJ) $(BONUS_OBJ) $(LIBS) $(MLXFLAGS) -o $(NAME)
	$(V)echo $(GREEN)"[$(NAME)] Executable created ✅"$(RESET)
	@touch $@

#################################
#        OBJ & DEP FILES        #
#################################
$(OBJDIR):
	$(V)mkdir -p $(OBJDIR) || true

DEP = $(OBJ:.o=.d)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

#################################
#             LIBFT             #
#################################
$(LIBFT):
	@$(V)echo '[$(NAME)] Downloading my Libft from github.com...'$(RESET)
	$(V)@git clone https://github.com/MathysCogne/MyLibft_GNL_Printf.git libft > /dev/null 2>&1
	@$(V)echo '[$(NAME)] Compiling Libft...'$(RESET)
	$(V)$(MAKE) --silent -C $(LIBFT_DIR)
	@$(V)echo '[$(NAME)] Libft build successfully'

#################################
#          MINILIBX             #
#################################
$(MINILIBX_DIR):
	$(V)echo '[$(NAME)] Downloading MiniLibX from github.com...'$(RESET)
	@git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR) > /dev/null 2>&1
	$(V)echo '[$(NAME)] Compiling MiniLibX...'$(RESET)
	@$(MAKE) -C $(MINILIBX_DIR) > /dev/null 2>&1
	$(V)echo '[$(NAME)] MiniLibX installed successfully'$(RESET)

#################################
#             CLEAN             #
#################################
	
clean:
	$(V)echo $(RED)'[$(NAME)] Cleaning objects'$(RESET)
	$(V)rm -rf $(OBJDIR)

fclean: clean
	$(V)echo $(RED)'[$(NAME)] Cleaning all files'$(RESET)
	$(V)rm -f $(NAME)
	$(V)echo $(RED)'[mlx] Remove directory'$(RESET)
	$(V)echo $(RED)'[libft] Remove directory'$(RESET)
	@rm -rf $(MINILIBX_DIR)
	@rm -rf $(LIBFT_DIR)


#################################
#             NORME             #
#################################
norme:
	@if (norminette src || norminette include) | grep "Error" > norminette_errors.txt; then \
		echo $(RED)"[$(NAME)] Norme KO"$(RESET); \
		cat norminette_errors.txt | awk 'BEGIN {FS=":"; OFS=":"} \
		/^src/ || /^libft/ || /^include/ {print "\n" $$0} \
		/^Error/ {sub(/^Error: /, ""); print "  ➜ " $$0}'; \
	else \
		echo $(GREEN)"[$(NAME)] Norme ok ✅"$(RESET); \
	fi
	@rm -f norminette_errors.txt

#################################
#             TEST              #
#################################
test: all norme
	$(V)echo $(GREEN)"[$(NAME)] Running $(NAME) with valgrind"$(RESET)
	$(V)valgrind --leak-check=full ./$(NAME) assets/map/labyrinthe.cub


re: fclean all

regen:
	makemyfile

.PHONY: all clean fclean re bonus regen norme test
.DEFAULT_GOAL := all
