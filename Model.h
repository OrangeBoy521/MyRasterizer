#pragma once
#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include "Mesh.h"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model
{
public:
    std::vector<Texture> textures_loaded;
    std::vector<Mesh> meshes;
    std::string directory;

    Model(std::string const &path)
    {
        loadModel(path);
    }

private:
    void loadModel(std::string const &path)
    {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
        {
            std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
        }

        directory = path.substr(0, path.find_last_of("/"));
        processNode(scene->mRootNode, scene);
    }

    void processNode(aiNode* node,const aiScene* scene)
    {
        for (unsigned int i = 0; i < node->mNumMeshes; ++i)
        {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(mesh, scene));
        }

        for (unsigned int i = 0; i < node->mNumChildren; ++i)
        {
            processNode(node->mNumChildren[i], scene);
        }
    }

    Mesh processMesh(aiMesh* mesh,const aiScene* scene)
    {
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> texture;


        for (unsigned int i = 0;i < mesh->mNumVertices; ++i)
        {
            Vertex vertex;
            Vector3D position;

            position.x = mesh->mVertices[i].x;
            position.y = mesh->mVertices[i].y;
            position.z = mesh->mVertices[i].z;
            vertex.position = Vector4D(position.x, position.y, position.z, 1.0f);

            if (mesh->HasNormals())
            {
				position.x = mesh->mVertices[i].x;
				position.y = mesh->mVertices[i].y;
				position.z = mesh->mVertices[i].z;

                vertex.normal = position;
            }

            if (mesh->mTextureCoords[0])
            {
                Vector2D vec;
                vec.x = mesh->mTextureCoords[0][i].x;
                vec.y = mesh->mTextureCoords[0][i].y;
                vertex.texcoord = vec;
            }
            else
            {
                vertex.texcoord = Vector2D(0.0f, 0.0f);
            }

            vertices.push_back(vertex);
        }

        for (unsigned int i = 0; i < mesh->mNumFaces; ++i)
        {
            aiFace face = mesh->mFaces[i];
            for (unsigned int j = 0;j < face.mNumIndices; ++j)
            {
                indices.push_back(face.mIndices[j]);    
            }
        }

        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];

        std::vector<Texture> normalMaps = loadModel()

        return Mesh(vertices, indices, texture);
    }

};

#endif