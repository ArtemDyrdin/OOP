cmake_minimum_required(VERSION 3.25)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_6 main.cpp Controls/Control.h Controls/ControlElements/Form.h Controls/ControlElements/Label.h Controls/ControlElements/TextBox.h Controls/ControlElements/ComboBox.h Controls/ControlElements/Button.h Factories/ControlFactory.h Factories/FactoryOS/WindowsControlFactory.h Factories/FactoryOS/LinuxControlFactory.h Factories/FactoryOS/MacOSControlFactory.h)
