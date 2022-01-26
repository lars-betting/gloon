#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H
// Forward declaration of SFML classes


namespace sf
{
	class Texture;
}

namespace Textures
{
	enum ID
	{
		Gloon,
		TempBackground
	};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif // BOOK_RESOURCEIDENTIFIERS_H