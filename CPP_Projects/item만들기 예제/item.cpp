#include "item.h"

Item::Item(): inuse (false)
{
}

Item::Item(int name, string title, int power, int maxuse, int curuse)
	: num(num), title(title), power(power), maxuse(maxuse), curuse(curuse), inuse(false) // 소스파일을 자동으로 만들어줌.
{
}
