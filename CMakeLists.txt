cmake_minimum_required(VERSION 3.20)
project(game)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(game main.cpp game/Field/Cell/Cell.cpp game/Field/Cell/Cell.h game/Field/Field.cpp game/Field/Field.h game/Iterator/Iterator.cpp game/Iterator/Iterator.h
        game/Builder/builder.h game/Builder/basefield_builder.cpp game/Builder/basefield_builder.h game/Entities/Entity.h
        game/Builder/Director.cpp game/Builder/Director.h game/game.h game/Entities/Player.cpp game/Entities/Player.h game/Entities/Enemy.h game/Entities/Ghost.cpp
        game/Entities/Ghost.h game/Entities/Object.h
        game/Drawers/DrawField.cpp game/Drawers/DrawField.h game/Entities/Enemy2.cpp game/Entities/Enemy2.h game/Entities/Enemy3.cpp game/Entities/Enemy3.h game/Entities/Weapon.cpp
        game/Entities/Weapon.h game/Entities/Armor.cpp game/Entities/Armor.h game/Entities/Heal.cpp game/Entities/Heal.h game/Entities/Key.cpp game/Entities/Key.h game/Logic/EntityLogic.h
        game/Logic/GhostLogic.cpp game/Logic/GhostLogic.h game/Logic/KeyLogic.cpp game/Logic/KeyLogic.h game/Logic/Enemy2Logic.cpp game/Logic/Enemy2Logic.h game/Logic/Enemy3Logic.cpp
        game/Logic/Enemy3Logic.h game/Logic/ObjectLogic.h game/Logic/ArmorLogic.cpp game/Logic/ArmorLogic.h game/Logic/WeaponLogic.cpp game/Logic/WeaponLogic.h game/Logic/HealLogic.cpp
        game/Logic/HealLogic.h game/Logic/PlayerLogic.cpp game/Logic/PlayerLogic.h game/Entities/Character.h game/Logs/Logger.h game/Logs/Observable.cpp game/Logs/Observable.h game/Logs/LoggerToConsole.cpp game/Logs/LoggerToConsole.h game/Logs/LoggerToFile.cpp game/Logs/LoggerToFile.h game/Drawers/DrawEntities.cpp game/Drawers/DrawEntities.h game/Logs/SetLogger.cpp game/Logs/SetLogger.h game/Rules/SizeOfFieldRule.h game/Rules/RuleForEnemy.h game/Rules/RuleForWin.h game/Control/GameControl.cpp game/Control/GameControl.h game/Save/Save.cpp game/Save/Save.h)
target_link_libraries(game sfml-graphics sfml-audio)