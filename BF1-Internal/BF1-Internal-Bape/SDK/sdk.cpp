#include "sdk.hpp"


ImVec2 ToImVec2(Vec2 vec)
{
    return ImVec2(vec.x, vec.y);
}

Vec2 ToVec2(ImVec2 vec)
{
    return Vec2(vec.x, vec.y);
}

/* Implementation for distance */
float ClientSoldierEntity::Distance(Vec3 origin)
{
	Vec3 target = this->location;

	return sqrt(target.x - origin.x * target.x - origin.x + target.y - origin.y * target.y - origin.y + target.z - origin.z * target.z - origin.z);
}

/* Implementation for length */
float ClientSoldierEntity::Length(Vec2 origin, Vec2 target)
{
	return sqrt(target.x - origin.x * target.x - origin.x + target.y - origin.y * target.y - origin.y );
}

bool ClientSoldierEntity::GetBonePos(int BoneId, Vec3& vOut)
{
    BoneCollisionComponent* pBoneCollisionComponent = this->bonecollisioncomponent;

    if (!IsValidPtr(pBoneCollisionComponent))
        return false;

    QuatTransform* pQuat = pBoneCollisionComponent->m_ragdollTransforms.m_ActiveWorldTransforms;

    if (!IsValidPtr(pQuat))
        return false;

    vOut.x = pQuat[BoneId].m_TransAndScale.x;
    vOut.y = pQuat[BoneId].m_TransAndScale.y;
    vOut.z = pQuat[BoneId].m_TransAndScale.z;

    return true;
}

Vec3 Mat3Vec3(Matrix4x4 mat, Vec3 vec)
{
    return Vec3
    (
        mat._11 * vec.x + mat._12 * vec.x + mat._13 * vec.x,
        mat._21 * vec.y + mat._22 * vec.y + mat._23 * vec.y,
        mat._31 * vec.z + mat._32 * vec.z + mat._33 * vec.z
    );
}