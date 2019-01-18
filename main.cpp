#include <SFML/Graphics.hpp>
#include "window.h"

using namespace std;

int main()
{
    Window * window = new Window();
    window->changePlace(WELCOME);
    return 0;
}
