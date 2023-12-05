cmake_minimum_required(VERSION 3.25)
project(lab_6)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_6 main.cpp Controls/Control.h Controls/Form.h Controls/Label.h Controls/TextBox.h Controls/ComboBox.h Controls/Button.h Factories/ControlFactory.h Factories/WindowsControlFactory.h Factories/LinuxControlFactory.h Factories/MacOSControlFactory.h)
