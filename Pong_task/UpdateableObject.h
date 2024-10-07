#pragma once

class UpdateableObject {
public:
	UpdateableObject();

	virtual void update() = 0;
};

