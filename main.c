// потом можно сделать таймер в программе ввода пароля, при неправильном вводе попытка повторится через...
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {

    // find terminal size
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

	int width = w.ws_col;
	int height = w.ws_row;


	struct point {
		int x;
		int y;
	}; 

	struct point start_point;

	start_point.x = -(width/2);
	start_point.y = -(height/2);  


	struct point end_point;

	end_point.x = width/2;
	end_point.y = height/2;

	// symbol position
	struct point character; 

	character.x = start_point.x;
	character.y = start_point.y;



	// rendering
	for (int frames = 0; frames < 1000; frames++) {

		for (int y = start_point.y; y < end_point.y; y++) {
            printf("\n");
			for (int x = start_point.x; x < end_point.x; x++) {

				if (x == character.x && y == character.y) {
					printf("O");
				}
				else {
					printf(".");
				}

			}
		}
		usleep(100 * 1000); // остановка на 100 мс

		character.x++;
		if (character.x == end_point.x) {
			character.x = start_point.x;
			character.y++;
		}
	}

	return 0;
}
