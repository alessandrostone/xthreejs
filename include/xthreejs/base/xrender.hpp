#ifndef XTHREE_RENDER_HPP
#define XTHREE_RENDER_HPP

#include <string>

#include "xwidgets/xmaterialize.hpp"
#include "xwidgets/xobject.hpp"
#include "xwidgets/xcolor.hpp"
#include "xwidgets/xholder.hpp"
#include "xwidgets/xtransport.hpp"

#include "xenums.hpp"
#include "xthree.hpp"
#include "../math/xplane_autogen.hpp"
#include "../renderers/webgl/xwebgl_shadow_map_autogen.hpp"
#include "../xgeometries.hpp"

namespace xthree
{

    //
    // xRenderWidget declaration
    //

    template <class D>
    class xRenderWidget : public xw::xwidget<D>
    {
    public:

        using base_type = xw::xwidget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(int, derived_type, _width, 200);
        XPROPERTY(int, derived_type, _height, 200);
        XPROPERTY(bool, derived_type, _antialias, false);

        XPROPERTY(bool, derived_type, autoClear, true);
        XPROPERTY(bool, derived_type, autoClearColor, true);
        XPROPERTY(bool, derived_type, autoClearDepth, true);
        XPROPERTY(bool, derived_type, autoClearStencil, true);
        XPROPERTY(std::vector<plane>, derived_type, clippingPlanes);
        XPROPERTY(double, derived_type, gammaFactor, 2.0);
        XPROPERTY(bool, derived_type, gammaInput, false);
        XPROPERTY(bool, derived_type, gammaOutput, false);
        XPROPERTY(bool, derived_type, localClippingEnabled, false);
        XPROPERTY(int, derived_type, maxMorphTargets, 8);
        XPROPERTY(int, derived_type, maxMorphNormals, 4);
        XPROPERTY(bool, derived_type, physicallyCorrectLights, false);
        XPROPERTY(webgl_shadow_map, derived_type, shadowMap, webgl_shadow_map());
        XPROPERTY(bool, derived_type, sortObject, true);
        XPROPERTY(std::string, derived_type, toneMapping, "LinearToneMapping", xenums::ToneMappings);
        XPROPERTY(double, derived_type, toneMappingExposure, 1.0);
        XPROPERTY(double, derived_type, toneMappingWhitePoint, 1.0);

        XPROPERTY(xw::html_color, derived_type, clearColor, "#000000");
        XPROPERTY(double, derived_type, clearOpacity, 1.0);

    protected:

        xRenderWidget();

        using base_type::base_type;

    private:

        void set_defaults();
    };

    //
    // xRenderWidget implementation
    //

    template <class D>
    inline void xRenderWidget<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(_width, state, buffers);
        xw::set_patch_from_property(_height, state, buffers);
        xw::set_patch_from_property(_antialias, state, buffers);
        xw::set_patch_from_property(autoClear, state, buffers);
        xw::set_patch_from_property(autoClearColor, state, buffers);
        xw::set_patch_from_property(autoClearDepth, state, buffers);
        xw::set_patch_from_property(autoClearStencil, state, buffers);
        xw::set_patch_from_property(clippingPlanes, state, buffers);
        xw::set_patch_from_property(gammaFactor, state, buffers);
        xw::set_patch_from_property(gammaInput, state, buffers);
        xw::set_patch_from_property(gammaOutput, state, buffers);
        xw::set_patch_from_property(localClippingEnabled, state, buffers);
        xw::set_patch_from_property(maxMorphTargets, state, buffers);
        xw::set_patch_from_property(maxMorphNormals, state, buffers);
        xw::set_patch_from_property(physicallyCorrectLights, state, buffers);
        xw::set_patch_from_property(shadowMap, state, buffers);
        xw::set_patch_from_property(sortObject, state, buffers);
        xw::set_patch_from_property(toneMapping, state, buffers);
        xw::set_patch_from_property(toneMappingExposure, state, buffers);
        xw::set_patch_from_property(toneMappingWhitePoint, state, buffers);
        xw::set_patch_from_property(clearColor, state, buffers);
        xw::set_patch_from_property(clearOpacity, state, buffers);
    }

    template <class D>
    inline void xRenderWidget<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(_width, patch, buffers);
        xw::set_property_from_patch(_height, patch, buffers);
        xw::set_property_from_patch(_antialias, patch, buffers);
        xw::set_property_from_patch(autoClear, patch, buffers);
        xw::set_property_from_patch(autoClearColor, patch, buffers);
        xw::set_property_from_patch(autoClearDepth, patch, buffers);
        xw::set_property_from_patch(autoClearStencil, patch, buffers);
        xw::set_property_from_patch(clippingPlanes, patch, buffers);
        xw::set_property_from_patch(gammaFactor, patch, buffers);
        xw::set_property_from_patch(gammaInput, patch, buffers);
        xw::set_property_from_patch(gammaOutput, patch, buffers);
        xw::set_property_from_patch(localClippingEnabled, patch, buffers);
        xw::set_property_from_patch(maxMorphTargets, patch, buffers);
        xw::set_property_from_patch(maxMorphNormals, patch, buffers);
        xw::set_property_from_patch(physicallyCorrectLights, patch, buffers);
        xw::set_property_from_patch(shadowMap, patch, buffers);
        xw::set_property_from_patch(sortObject, patch, buffers);
        xw::set_property_from_patch(toneMapping, patch, buffers);
        xw::set_property_from_patch(toneMappingExposure, patch, buffers);
        xw::set_property_from_patch(toneMappingWhitePoint, patch, buffers);
        xw::set_property_from_patch(clearColor, patch, buffers);
        xw::set_property_from_patch(clearOpacity, patch, buffers);
    }

    template <class D>
    inline xRenderWidget<D>::xRenderWidget()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xRenderWidget<D>::set_defaults()
    {
        this->_model_module() = "jupyter-threejs";
        this->_model_module_version() = "1.0.0-beta.3";
        this->_view_module() = "jupyter-threejs";
        this->_view_module_version() = "1.0.0-beta.3";

    }

    //
    // xpreview declaration
    //

    template <class D>
    class xpreview : public xRenderWidget<D>
    {
    public:

        using base_type = xRenderWidget<D>;
        using derived_type = D;

        using child_type = xw::xholder<xthree_widget>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(bool, derived_type, _flat, false);
        XPROPERTY(bool, derived_type, _wire, false);
        XPROPERTY(child_type, derived_type, child);

        template <class T>
        xpreview(xthree_widget<T>&);

        template <class T>
        xpreview(const xthree_widget<T>&);

        template <class T>
        xpreview(xthree_widget<T>&&);

    private:

        void set_defaults();
    };

    using preview = xw::xmaterialize<xpreview>;
    using preview_generator = xw::xgenerator<xpreview>;

    //
    // xpreview implementation
    //

    template <class D>
    inline void xpreview<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(_flat, state, buffers);
        xw::set_patch_from_property(_wire, state, buffers);
        xw::set_patch_from_property(child, state, buffers);
    }

    template <class D>
    inline void xpreview<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(_flat, patch, buffers);
        xw::set_property_from_patch(_wire, patch, buffers);
        xw::set_property_from_patch(child, patch, buffers);
    }

    template <class D>
    template <class T>
    inline xpreview<D>::xpreview(xthree_widget<T>& child_)
        : base_type()
    {
        this->child = xw::make_id_holder<xthree_widget>(child_.id());
        set_defaults();
    }

    template <class D>
    template <class T>
    inline xpreview<D>::xpreview(const xthree_widget<T>& child_)
        : base_type()
    {
        this->child = xw::make_id_holder<xthree_widget>(child_.id());
        set_defaults();
    }

    template <class D>
    template <class T>
    inline xpreview<D>::xpreview(xthree_widget<T>&& child_)
        : base_type()
    {
        this->child = xw::make_owning_holder(std::move(child_));
        set_defaults();
    }

    template <class D>
    inline void xpreview<D>::set_defaults()
    {
        this->_model_name() = "PreviewModel";
        this->_view_name() = "PreviewView";
    }
}

// namespace xw
// {
//     XPRECOMPILE_WITH_ARG1(EXTERN, (xthree::xpreview),
//         (
//             xthree::box_buffer_geometry,
//             xthree::box_geometry,
//             xthree::circle_buffer_geometry,
//             xthree::circle_geometry,
//             xthree::cone_geometry,
//             xthree::cylinder_buffer_geometry,
//             xthree::cylinder_geometry,
//             xthree::dodecahedron_geometry,
//             xthree::edges_geometry,
//             xthree::extrude_geometry,
//             xthree::icosahedron_geometry,
//             xthree::lathe_buffer_geometry,
//             xthree::lathe_geometry,
//             xthree::octahedron_geometry,
//             xthree::parametric_geometry,
//             xthree::plane_buffer_geometry,
//             xthree::plane_geometry,
//             xthree::polyhedron_geometry,
//             xthree::ring_buffer_geometry,
//             xthree::ring_geometry,
//             xthree::shape_geometry,
//             xthree::sphere_buffer_geometry,
//             xthree::sphere_geometry,
//             xthree::tetrahedron_geometry,
//             xthree::text_geometry,
//             xthree::torus_buffer_geometry,
//             xthree::torus_geometry,
//             xthree::torus_knot_buffer_geometry,
//             xthree::torus_knot_geometry,
//             xthree::tube_geometry,
//             xthree::wireframe_geometry
//         )
//     )
// }
#endif