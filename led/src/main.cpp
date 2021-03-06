/*
 * Copyright (c) 2011, 2012, 2013  BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/device/Led>

using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
    // Register our class that wraps the C++ Led interface with QML so that we
    // can make calls into the Led and get results, through QML.
    qmlRegisterType<bb::device::Led>("bb.device", 1, 0, "Led");
    qmlRegisterUncreatableType<bb::device::LedColor>("bb.device", 1, 0, "LedColor", "");

    Application app(argc, argv);

    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    ApplicationUI appui;

    return Application::exec();
}
