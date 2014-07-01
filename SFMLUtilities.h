#ifndef SFMLUTILITIES_H
#define SFMLUTILITIES_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <random>
#include <chrono>

namespace zmc
{
class SFMLUtilities
{
public:
    /**
     * @brief It's the position of the sprite
     */
    typedef sf::Vector2f State;
public:
    SFMLUtilities(unsigned int seed);
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
     * @brief Returns the center position of the screen relative to the sprite size. Be sure to provide
     * scaled size of the sprite
     * @param parentSize
     * @param spriteSize
     * @return
     */
    static sf::Vector2f getCenterPosition(sf::Vector2u parentSize, sf::Vector2u spriteSize);
    /**
     * @brief Returns a sprite's scaled size
     * @param sprite
     * @return sf::Vector2f
     */
    static sf::Vector2u getScaledSize(const sf::Sprite &sprite);
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
    static const sf::IntRect getScaledTextureRect(const sf::Sprite &sprite);

    /**
     * @brief Returns the generated random number using Mersenne-Twister algorithm
     * @param start --> Starting number for the generator. This numer is included
     * @param end --> End number for the generator. This numer is included
     * @return Random number
     */
    int generateRandomNumber(int start, int end);
    void setSeedForRandomNumberGeneration(unsigned int seed);

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
    static float distanceBetweenTwoVectors(sf::Vector2f firstVector, sf::Vector2f secondVector);
    static float getAngleBetweenTwoVectors(sf::Vector2f firstVector, sf::Vector2f secondVector);
    static bool intersects(const sf::Sprite *firstSprite, const sf::Sprite *secondSprite);

private:
    unsigned int mSeed;
    std::mt19937 eng;
};
}
#endif // SFMLUTILITIES_H
