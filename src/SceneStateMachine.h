#pragma once

#include <memory>
#include <unordered_map>

#include "Scene.h"
#include "Window.h"

class SceneStateMachine {
public:
    SceneStateMachine();

    auto processInput() -> void;
    auto update(float deltaTime) -> void;
    auto lateUpdate(float deltaTime) -> void;
    auto draw(Window& window) -> void;

    auto add(const std::shared_ptr<Scene>& scene) -> unsigned int;
    auto switchTo(unsigned int id) -> void;
    auto remove(unsigned int id) -> void;
private:
    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
    std::shared_ptr<Scene> currentScene;
    unsigned int insertedSceneId;
};