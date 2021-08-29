#ifndef ENGINE_ENGINE_H
#define ENGINE_ENGINE_H

#include "gui/WindowManager.h"


namespace Engine {
    class Engine {
    public:
        Engine() = default;
        Engine(const Engine&) = delete;
        Engine(Engine&&) = delete;
        Engine& operator=(const Engine&) = delete;
        Engine& operator=(Engine&&) = delete;
        ~Engine() = default;

        virtual int initialize();
        int execute();

    protected:
        Gui::WindowManager m_manager;
    };
}


#endif // ENGINE_ENGINE_H
