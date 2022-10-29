set(HEADERS Object.h Actor.h ActorComponent.h ObjectFactory.h)
set(SOURCES Object.cpp Actor.cpp ActorComponent.cpp ObjectFactory.cpp SceneComponent.cpp SceneComponent.h)

add_library(engine-core OBJECT ${HEADERS} ${SOURCES})
set_property(TARGET engine-core PROPERTY POSITION_INDEPENDENT_CODE ON)

