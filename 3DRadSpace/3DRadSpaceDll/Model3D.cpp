#include "pch.h"
#include "Model3D.h"

_3DRadSpaceDll::Model3D* _3DRadSpaceDll::Model3D::FromFileBasic(char* file)
{
    Assimp::Importer imp;
    aiScene *scene = (aiScene*)imp.ReadFile(file, aiProcess_Triangulate | aiProcess_FlipUVs);
    
    if (scene == nullptr) return nullptr;

    this->Meshes = _newdp<Mesh>(scene->mNumMeshes);

    //initialize vertex buffers.
    for (int i = 0; i < scene->mNumMeshes; i++)
    {
        const size_t s_vertexbuff = sizeof(Vector3) * scene->mMeshes[i]->mNumVertices;
        for (size_t j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
        {
            this->Meshes[i]->Parts = _newdp<MeshPart>(scene->mMeshes[i]->mFaces[j].mNumIndices);
            memcpy_s(this->Meshes[i]->Parts[j]->Buffer, s_vertexbuff, scene->mMeshes[i]->mVertices, s_vertexbuff);
        }
        
        //initialize index buffers

        for (size_t j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
        {
            size_t numind = scene->mMeshes[i]->mFaces[j].mNumIndices;

            this->Meshes[i]->Parts[j]->Indicies = new int[numind];

            this->Meshes[i]->Parts[j]->Size = numind;

            memcpy_s(this->Meshes[i]->Parts[j]->Indicies, numind * sizeof(int), scene->mMeshes[i]->mFaces[j].mIndices, numind * sizeof(int));
        }
    }
    return new Model3D();
}
