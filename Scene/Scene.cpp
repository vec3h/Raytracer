//
// Created by Виталий on 23.12.2017.
//

#include "Scene.h"

void Scene::Add(Renderable &renderable) {
    renderables.push_back(&renderable);
}