//
// Created by Виталий on 10.12.2017.
//

#ifndef RAYTRACER_RAYTRACER_H
#define RAYTRACER_RAYTRACER_H

#include <algorithm>
#include <fstream>
#include <vector>
#include "../Math/Vec3.h"
#include "../Primitives/Sphere.h"
#include "../Scene/Scene.h"
#include "../Camera/Camera.h"
#include "../TaskManager/TaskManager.h"

#define MAX_RAY_DEPTH 5
#define BACKGROUND 0.235294, 0.67451, 0.843137

class Raytracer {
private:
    int frameBufferWidth;
    int frameBufferHeight;
    float aspectRatio;
    float invWidth;
    float invHeight;
    float angle;

    Scene &scene;
    Camera &camera;
    TaskManager &taskManager;

public:
    Raytracer(int frameBufferWidth, int frameBufferHeight, Scene &scene, Camera &camera,  TaskManager &taskManager);
    void render(std::vector<Vec3f> &image);

private:
    Vec3f castRay(const Vec3f &orig, const Vec3f &dir, uint32_t depth);
    bool trace(const Vec3f &orig, const Vec3f &dir, float &tNear, uint32_t &index, Vec2f &uv, Renderable **hitObject);
};


#endif //RAYTRACER_RAYTRACER_H
