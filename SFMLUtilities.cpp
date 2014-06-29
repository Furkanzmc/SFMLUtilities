#include "SFMLUtilities.h"
#include <random>
#include <chrono>

namespace zmc
{
SFMLUtilities::SFMLUtilities()
{
}

sf::Vector2f SFMLUtilities::getCenterPosition(sf::Vector2u parentSize, sf::Sprite &sprite)
{
    sf::Vector2f vector((int)parentSize.x / 2 - (sprite.getTexture()->getSize().x / 2) * sprite.getScale().x , (int)parentSize.y / 2 - (sprite.getTexture()->getSize().y / 2)
                        * sprite.getScale().y);
    return vector;
}

sf::Vector2f SFMLUtilities::getScaledSize(const sf::Sprite &sprite)
{
    sf::Vector2f vector;
    vector = sf::Vector2f(sprite.getTexture()->getSize().x  * sprite.getScale().x , sprite.getTexture()->getSize().y * sprite.getScale().y);
    return vector;
}

const std::vector<int> SFMLUtilities::getDigits(int n)
{
    std::vector<int> array;
    std::vector<int> array2;
    if (n == 0) {
        array2.push_back(0);
        return array2;
    }
    int number = n;
    while (number > 0) {
        int mod = number % 10;
        array.push_back(mod);
        number -= mod;
        number /= 10;
    }
    for (unsigned int i = array.size() - 1; i < array.size(); i--) {
        array2.push_back(array.at(i));
    }
    return array2;
}

const sf::IntRect SFMLUtilities::getScaledTextureRect(const sf::Sprite &sprite)
{
    sf::IntRect intRect;
    intRect.top = (int)sprite.getPosition().y;
    intRect.left = (int)sprite.getPosition().x;
    intRect.height = (int)getScaledSize(sprite).y;
    intRect.width = (int)getScaledSize(sprite).x;
    return intRect;
}

int SFMLUtilities::generateRandomNumber(int start, int end)
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 eng((unsigned int)seed);
    std::uniform_int_distribution<> distr(start, end);
    return distr(eng);
}

sf::Vector2f SFMLUtilities::getFitToAlignScale(sf::Vector2u textureSize, sf::Vector2u containerSize)
{
    float imageHeight = (float)textureSize.y;
    float imageWidth = (float)textureSize.x;
    float rImage = imageWidth / imageHeight;
    float screenHeight = (float)containerSize.y;
    float screenWidth = (float)containerSize.x;
    float rScreen = screenWidth / screenHeight;
    //    rs > ri ? (wi * hs/hi, hs) : (ws, hi * ws/wi)
    sf::Vector2f size(rScreen > rImage ? (imageWidth * screenHeight / imageHeight) : screenWidth,
                      rScreen > rImage ? screenHeight : imageHeight * screenWidth / imageWidth);

    float scalex = (float)size.x / (float)textureSize.x;
    float scaley = (float)size.y / (float)textureSize.y;
    return sf::Vector2f(scalex, scaley);
}

float SFMLUtilities::toSFMLCoordinate(float box2dCoord)
{
    return box2dCoord * 30;
}

float SFMLUtilities::toBox2DCoordinate(float sfmlCoord)
{
    return sfmlCoord / 30;
}

float SFMLUtilities::toDegree(float radian)
{
    const float PI = 3.14159265f;
    return (radian * 180 / PI);
}

float SFMLUtilities::toRadian(float degree)
{
    const float PI = 3.14159265f;
    return (degree * PI / 180);
}

float SFMLUtilities::distanceBetweenTwoVectors(sf::Vector2f firstVector, sf::Vector2f secondVector)
{
    return std::sqrt(std::pow((firstVector.x - secondVector.x), 2) + std::pow((firstVector.y - secondVector.y), 2));
}

float SFMLUtilities::getAngleBetweenTwoVectors(sf::Vector2f firstVector, sf::Vector2f secondVector)
{
    float rotation = 0;
    rotation = (float) toDegree(std::atan2(firstVector.x - secondVector.x, firstVector.y - secondVector.y));
    if (rotation < 0) {
        rotation += 360;
    }
    return rotation;
}

bool SFMLUtilities::intersects(const sf::Sprite *firstSprite, const sf::Sprite *secondSprite)
{
    sf::IntRect firstRect((int)firstSprite->getPosition().x, (int)firstSprite->getPosition().y
                          , (int)getScaledSize(*firstSprite).x, (int)getScaledSize(*firstSprite).y);
    sf::IntRect secondRect((int)secondSprite->getPosition().x, (int)secondSprite->getPosition().y
                           , (int)getScaledSize(*secondSprite).x, (int)getScaledSize(*secondSprite).y);
    return firstRect.intersects(secondRect);
}
}
