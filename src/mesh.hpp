#ifndef MESH_HPP
#define MESH_HPP

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"
#include <algorithm>
#include <cstdlib>
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

struct bvh {
    float boundingbox[6];
    bvh* left;
    bvh* right;
};

bvh* new_node(float bb[6]) {
    bvh* newnode = new bvh();
    for(int i = 0;i < 6;++i) {
        newnode->boundingbox[i] =  bb[i];
    }
    newnode->left = nullptr;
    newnode->right = nullptr;
    return newnode;
}

#endif
