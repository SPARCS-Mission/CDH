#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Types/Assert.hpp>
#include <cstdio>

#if FW_PORT_SERIALIZATION == 1

namespace Fw {

    // SerializePort has no call interface. It is to pass through serialized data
    InputSerializePort::InputSerializePort() : InputPortBase(), m_func(nullptr) {
    }
    InputSerializePort::~InputSerializePort() {
    }

    void InputSerializePort::init() {
        InputPortBase::init();

    }

    SerializeStatus InputSerializePort::invokeSerial(SerializeBufferBase &buffer) {
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);

        this->m_func(this->m_comp,this->m_portNum,buffer);

        // The normal input ports perform deserialize() on the passed buffer,
        // which is what this status is based on.  This is not the case for the
        // InputSerializePort, so just return an okay status
        return FW_SERIALIZE_OK;
    }

    void InputSerializePort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);
        this->m_comp = callComp;
        this->m_func = funcPtr;
    }

#if FW_OBJECT_TO_STRING == 1
    const char* InputSerializePort::getToStringFormatString() {
        return "Input Serial Port: %s %s->(%s)";
    }
#endif

}
#endif
