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
#ifndef SIGNALSLOTJS_HPP_
#define SIGNALSLOTJS_HPP_

#include <string>
#include <pthread.h>
#include "../public/plugin.h"

class SignalSlot: public JSExt {

public:
    explicit SignalSlot(const std::string& id);
    virtual ~SignalSlot();

// Interfaces of JSExt
    virtual bool CanDelete();
    virtual std::string InvokeMethod(const std::string& command);

    void NotifyEvent(const std::string& event);

private:

    bool StartThread();

    std::string m_id;
    pthread_t m_thread;
};

#endif /* SIGNALSLOTJS_HPP_ */
