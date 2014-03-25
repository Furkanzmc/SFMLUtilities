#ifndef SFMLUTILITIES_H
#define SFMLUTILITIES_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>

namespace zmc
{
class SFMLUtilities
{
public:
    typedef sf::Vector2f Derivative;
    /**
     * @brief It's the position of the sprite
     */
    typedef sf::Vector2f State;
public:
    SFMLUtilities();
    /**
     * @brief Returns the center position of the screen relative to the sprite
     * @param parentWidht
     * @param parentHeight
     * @param sprite
     * @return Return value is set to the sprite to center it on the screen
     */
    static sf::Vector2f getCenterPosition(sf::Vector2u parentSize, sf::Sprite &sprite);
    /**
     * @brief Returns a sprite's scaled size
     * @param sprite
     * @return sf::Vector2f
     */
    static sf::Vector2f getScaledSize(sf::Sprite &sprite, const sf::IntRect &customRect = sf::IntRect(0, 0, 0, 0));
    /**
     * @brief Returns a vector<int> with the numbers
     */
    static const std::vector<int> getDigits(int n);

    /**
     * @brief When a sprite is scaled, texture rect stays the same as the original image size. This function returns a rectangle
     *that covers the scaled sprite
     * @param sprite
     * @return Scaled sf::IntRect
     */
    static const sf::IntRect getScaledTextureRect(sf::Sprite &sprite);

    /**
     * @brief Returns the generated random number using Mersenne-Twister algorithm
     * @param start --> Starting number for the generator. This numer is included
     * @param end --> End number for the generator. This numer is included
     * @param seed --> The variable to seed the generator, default value is 0
     * @return Random number
     */
    static int generateRandomNumber(int start, int end, int seed = 0);

    static sf::Vector2f getFitToAlignScale(sf::Vector2u textureSize, sf::Vector2u containerSize);
    /**
     * @brief 1 meter is 30 pixels
     * @param box2dCoord
     * @return
     */
    static float toSFMLCoordinate(float box2dCoord);
    /**
     * @brief 1 meter is 30 pixels
     * @param sfmlCoord
     * @return
     */
    static float toBox2DCoordinate(float sfmlCoord);
    static float toDegree(float radian);
    static float toRadian(float degree);

private:
    sf::Vector2f mDerivative;
};
}
#endif // SFMLUTILITIES_H
