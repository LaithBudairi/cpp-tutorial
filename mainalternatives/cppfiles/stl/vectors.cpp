//
// Created by LaithB on 11/29/2020.
//

#include <vector>
#include <iostream>
struct Vertex {
    float x, y, z;

    Vertex (float x, float y, float z) : x(x), y(y), z(z){};
    Vertex (const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z){
        std::cout << "copied" << std::endl;
    };
};

struct Vector2 {
    float x, y;

    Vector2(float x, float y) : x(x), y(y) {};

    Vector2 add(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2 operator+(const Vector2& other) const {
        return add(other);
    }

    Vector2 multiply(const Vector2& other) const {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2& other) const {
        return multiply(other);
    }

    bool operator==(const Vector2& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2& other) const {
        return !(*this == other);
    }
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
}

std::ostream& operator<<(std::ostream& stream, const Vector2& vertex) {
    stream << vertex.x << ", " << vertex.y;
}
void vectors() {
    std::vector<Vertex> vertices;

    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});

    for(int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << std::endl;
    }

    vertices.erase(vertices.begin() + 1);

    for(Vertex &v : vertices) {
        std::cout << v << std::endl;
    }

    // Operator overloading
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerUp(1.1f, 1.1f);

    Vector2 result1 = position.add(speed.multiply(powerUp));
    Vector2 result2 = position + speed * powerUp;

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;

    // vector optimizing
    std::cout << "Vector Optimization\n\n";
    std::vector<Vertex> vertices2;

    //Optimization1:
    vertices2.reserve(3);

    vertices2.emplace_back(7, 8, 9);
    vertices2.emplace_back(10, 11, 12);
    vertices2.emplace_back(13, 14, 15);


}