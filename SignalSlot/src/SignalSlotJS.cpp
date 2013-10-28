/*
* Copyright 2013 Hasan Ahmad.
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

#include <string>
#include <sstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "SignalSlotJS.hpp"
#include <QtCore/QCoreApplication>
#include "SignalHandler.hpp"

using namespace std;

SignalSlot::SignalSlot(const std::string& id) : m_id(id) {
    m_thread = 0;
}

SignalSlot::~SignalSlot() {
}

char* onGetObjList() {
    static char name[] = "SignalSlot";
    return name;
}

JSExt* onCreateObject(const string& className, const string& id) {
    if (className == "SignalSlot") {
        return new SignalSlot(id);
    }
    return NULL;
}

bool SignalSlot::CanDelete() {
    return true;
}

string SignalSlot::InvokeMethod(const string& command) {
    if (command == "start") {
        if (StartThread()) {
        	return "Started";
        } else {
        	return "Not Started";
        }
    } else {
        return "Unsupported Method";
    }
}

void* SignalThread(void* parent) {
    SignalSlot *pParent = static_cast<SignalSlot *>(parent);

    int argc = 0;
    char **argv = NULL;
    QCoreApplication QCoreApplication(argc, argv);
    SignalHandler *m_signalHandler = new SignalHandler(pParent);
    QCoreApplication::exec();
    delete m_signalHandler;
    return NULL;
}


bool SignalSlot::StartThread() {
    if (!m_thread) {
        pthread_attr_t thread_attr;
        pthread_attr_init(&thread_attr);
        pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);

        pthread_create(&m_thread, &thread_attr, SignalThread,
                static_cast<void *>(this));
        pthread_attr_destroy(&thread_attr);
        return true;
    } else {
        return false;
    }
}

void SignalSlot::NotifyEvent(const std::string& event) {
    std::string eventString = m_id + " ";
    eventString.append(event);
    SendPluginEvent(eventString.c_str(), m_pContext);
}



