#include "mesh.hpp"

Mesh::Mesh(std::vector<float> pts, std::vector<std::size_t> conn) {
    points = pts;
    triangles = conn;
}

Mesh::Mesh(std::string filename) {
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(filename,
                                             aiProcess_Triangulate | aiProcess_JoinIdenticalVertices | aiProcess_GenNormals);

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
        std::cout << "Error loading mesh: " << importer.GetErrorString() << "\n";
        exit(1);
    }

    for (unsigned int meshIndex = 0; meshIndex < scene->mNumMeshes; ++meshIndex) {
        const aiMesh* mesh = scene->mMeshes[meshIndex];
        for (unsigned int vertexIndex = 0; vertexIndex < mesh->mNumVertices; ++vertexIndex) {
            points.push_back(mesh->mVertices[vertexIndex].x);
            points.push_back(mesh->mVertices[vertexIndex].y);
            points.push_back(mesh->mVertices[vertexIndex].z);
        }

        for (unsigned int faceIndex = 0; faceIndex < mesh->mNumFaces; ++faceIndex) {
            if (mesh->mFaces[faceIndex].mNumIndices == 3) {
                triangles.push_back((std::size_t) mesh->mFaces[faceIndex].mIndices[0]);
                triangles.push_back((std::size_t) mesh->mFaces[faceIndex].mIndices[1]);
                triangles.push_back((std::size_t) mesh->mFaces[faceIndex].mIndices[2]);
            }
            else {
                std::cout << "Warning: Skipping non-triangle face. \n";
            }
        }
    }
}
