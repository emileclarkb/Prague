#include "prague.h"
#include <vector>

#include "Prague/Core/Scripts/Display.h"

std::vector<Prague*>* scripts() {
	std::vector<Prague*>* refs;
	refs->push_back(new Display);

	return refs;
}