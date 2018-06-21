/*
* Viry3D
* Copyright 2014-2018 by Stack - stackos@qq.com
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "Material.h"
#include "Shader.h"
#include "Renderer.h"

namespace Viry3D
{
    Material::Material(const Ref<Shader>& shader):
        m_shader(shader)
    {
    
    }

    Material::~Material()
    {
    
    }
    
    int Material::GetQueue() const
    {
        if (m_queue)
        {
            return *m_queue;
        }

        return m_shader->GetRenderState().queue;
    }
    
    void Material::SetQueue(int queue)
    {
        m_queue = RefMake<int>(queue);

        for (auto i : m_renderers)
        {
            i->MarkRendererOrderDirty();
        }
    }

    void Material::OnSetRenderer(Renderer* renderer)
    {
        m_renderers.AddLast(renderer);
    }

    void Material::OnUnSetRenderer(Renderer* renderer)
    {
        m_renderers.Remove(renderer);
    }
}