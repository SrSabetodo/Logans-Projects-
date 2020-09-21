#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(300, 300), "My window");
	Texture t1;

	if (!t1.loadFromFile("dirt.jpg"))
	{
		return EXIT_FAILURE;
	}

	Sprite s(t1);

	Event e;

	while (window.isOpen())
	{
		while (window.pollEvent(e))
		{
			
			if (e.type == Event::Closed)
			{
				window.close();
			}

			if (e.type == Event::KeyPressed)
			{
				window.close();
			}

			window.clear();

			window.draw(s);

			window.display();
		}
	}
}