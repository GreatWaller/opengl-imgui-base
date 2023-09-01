#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include<iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main()
{
    glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
    // 译注：下面就是矩阵初始化的一个例子，如果使用的是0.9.9及以上版本
    // 下面这行代码就需要改为:
    glm::mat4 trans = glm::mat4(1.0f);

    trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));
    vec = trans * vec;
    std::cout << vec.x << vec.y << vec.z << std::endl;

    int width, height, nrChannels;
    unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
    std::cout<< width << height<< nrChannels<<std::endl;
}