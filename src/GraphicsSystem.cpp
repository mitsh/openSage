// Stephan Vedder 2015
#include "GraphicsSystem.hpp"
#include "Graphics/flextGL.h"
#include "Graphics/Video.hpp"
#include <glm/gtc/matrix_transform.hpp>
using namespace Graphics;

std::vector<std::shared_ptr<Graphics::IRenderable>> GraphicsSystem::m_videos;
std::vector<std::shared_ptr<Graphics::Shader>> GraphicsSystem::m_shaders;
glm::mat4 GraphicsSystem::m_ortho;

void GraphicsSystem::Initialize()
{
    flextInit();

    //our 2D mvp matrix
    m_ortho = glm::ortho(0.0f, 1024.0f, 768.0f, 0.0f, 0.1f, 100.0f);
    //video shader
    m_shaders.push_back(std::make_shared<Shader>());
    m_shaders.back()->LoadFromFile(Shader::VERTEX_SHADER, "shader/video.vert");
    m_shaders.back()->LoadFromFile(Shader::FRAGMENT_SHADER, "shader/video.frag");
    m_shaders.back()->Link();
}

void GraphicsSystem::Release()
{

}

void GraphicsSystem::Clear()
{
    //clear the screen
    glClear(GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void GraphicsSystem::Render()
{
    //m_shaders[VIDEO_SHADER]->Use();
    
    //for (auto& renderable : m_videos)
    //{
    //    renderable->Render(*m_shaders[VIDEO_SHADER]);
    //}

    //m_shaders[VIDEO_SHADER]->UnUse();
}

void GraphicsSystem::Update()
{
    for (auto& renderable : m_videos)
    {
        renderable->Update();
    }
}

void GraphicsSystem::AddVideo(std::shared_ptr<IRenderable> renderable)
{
    m_videos.push_back(renderable);
}