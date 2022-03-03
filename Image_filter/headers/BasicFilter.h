#include <sstream>
#include <vector>
#include "Filter.h"

class GrayScaleFilter{//:Filter {
public:
	void apply(Image* image);

};
class WarmFilter{//:Filter {
public:
	void apply(Image* image);

};
class CoolFilter{//:Filter {
public:
	void apply(Image* image);

};
class SepiaFilter{//:Filter {
public:
	void apply(Image* image);

};
class PencilFilter{//:Filter {
public:
	void apply(Image* image);

};
class InvertFilter{//:Filter {
public:
	void apply(Image* image);

};