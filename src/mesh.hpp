#ifndef MESH_HPP
#define MESH_HPP

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include <iostream>
#include <string>
#include <vector>

class Mesh {
    public:
        std::vector<float> points;
        std::vector<std::size_t> triangles;
        Mesh(std::vector<float> pts, std::vector<std::size_t> conn);
        Mesh(std::string filename);
};

void load_mesh(std::string filename);
void processNode(aiNode* node, const aiScene* scene); 
Mesh processMesh(aiMesh* mesh);


#endif
