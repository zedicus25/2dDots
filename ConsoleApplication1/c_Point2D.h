#pragma once
class c_Point2D
{
private:
	int x;
	int y;
public:
	c_Point2D()
	{
		this->x = 0;
		this->y = 0;
	}
	//sets
	inline void setX(int x) {
		this->x = x;
	}
	inline void setY(int y) {
		this->y = y;
	}

	//gets
	inline int getX() const {
		return this->x;
	}
	inline int getY() const {
		return this->y;
	}
};

