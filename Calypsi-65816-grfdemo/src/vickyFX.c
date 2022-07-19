

int setVickyBorder(bool show, uint8_t x, uint8_t y);
int setBorderColor(uint8_t red, uint8_t green, uint8_t blue);


int setVickyBorder(bool show, uint8_t x, uint8_t y)
{
	if (show==true)
		BORDER_CTRL_REG	= 1;
	BORDER_X_SIZE = x & 31;
	BORDER_Y_SIZE = x & 31;
}

int setBorderColor(uint8_t red, uint8_t green, uint8_t blue)
{
	BORDER_COLOR_B=blue;
	BORDER_COLOR_G=green;
	BORDER_COLOR_R=red;
}