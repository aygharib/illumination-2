#include "SceneStateMachine.h"

#include <iostream>

SceneStateMachine::SceneStateMachine() : currentScene(nullptr), insertedSceneId(0) {}

auto SceneStateMachine::processInput() -> void {
    if (currentScene) {
        currentScene->processInput();
    }
}

auto SceneStateMachine::update(float deltaTime) -> void {
    if (currentScene) {
        currentScene->update(deltaTime);
    }
}

auto SceneStateMachine::lateUpdate(float deltaTime) -> void {
    if (currentScene) {
        currentScene->lateUpdate(deltaTime);
    }
}

auto SceneStateMachine::draw(Window& window) -> void {
    if (currentScene) {
        currentScene->draw(window);
    }
}

auto SceneStateMachine::add(std::shared_ptr<Scene> scene) -> unsigned int {
    auto inserted = scenes.insert(std::make_pair(insertedSceneId, scene));

    // .first selects the iterator returned from insert (<iterator, bool>)
        // The bool is used to check whether the insertion was successful, which we don't use at the moment (although we will in future). So we are only interested in the first value, the iterator
    // access the iterator which points to newly inserted pair (<sceneId, scene>)
    // ->second selects the scene
    inserted.first->second->onCreate();

    return insertedSceneId++;
}

auto SceneStateMachine::switchTo(unsigned int id) -> void {
    auto it = scenes.find(id);
    if (it != scenes.end()) {
        if (currentScene) {
            currentScene->onDeactivate();
        }
        
        currentScene = it->second;
        currentScene->onActivate();
    }
}

auto SceneStateMachine::remove(unsigned int id) -> void {
    auto it = scenes.find(id);

    if (it != scenes.end()) {
        if (currentScene == it->second) {
            currentScene = nullptr;
        }

        it->second->onDestroy();
        scenes.erase(it);
    }
}