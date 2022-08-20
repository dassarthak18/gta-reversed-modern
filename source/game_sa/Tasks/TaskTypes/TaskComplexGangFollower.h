#pragma once

#include "TaskComplex.h"
#include "Vector.h"

class CPedGroup;

class CTaskComplexGangFollower : public CTaskComplex {
public:
    CPedGroup* m_PedGroup;
    CPed*      m_Ped;
    CVector    m_PedPosn;
    CVector    dword20;
    CVector    dword2C;
    float      dword38;
    uint8      byte3C;
    uint8      m_Flags;
    int32      dword40;
    int32      dword44;
    uint8      byte48;
    uint8      byte49;

public:
    static constexpr auto Type = eTaskType::TASK_COMPLEX_GANG_FOLLOWER;

    CTaskComplexGangFollower(CPedGroup* pedGroup, CPed* ped, uint8 a4, CVector pos, float a6);
    ~CTaskComplexGangFollower() override;

    eTaskType GetTaskType()  override{ return Type; }
    CTask* Clone() override;
    bool MakeAbortable(CPed* ped, eAbortPriority priority, const CEvent* event) override;
    CTask* CreateNextSubTask(CPed* ped) override;
    CTask* CreateFirstSubTask(CPed* ped) override;
    CTask* ControlSubTask(CPed* ped) override;

    void CalculateOffsetPosition(CVector& pos);

private:
    friend void InjectHooksMain();
    static void InjectHooks();
    CTaskComplexGangFollower* Constructor(CPedGroup* pedGroup, CPed* ped, uint8 uint8, CVector pos, float a6) { this->CTaskComplexGangFollower::CTaskComplexGangFollower(pedGroup, ped, uint8, pos, a6); return this; }
    CTaskComplexGangFollower* Destructor() { this->CTaskComplexGangFollower::~CTaskComplexGangFollower(); return this; }
};
VALIDATE_SIZE(CTaskComplexGangFollower, 0x4C);