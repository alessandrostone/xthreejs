#ifndef XTHREE_DODECAHEDRON_GEOMETRY_HPP
#define XTHREE_DODECAHEDRON_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // dodecahedron_geometry declaration
    //

    template<class D>
    class xdodecahedron_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, radius, 1);
        XPROPERTY(int, derived_type, detail, 0);
        XPROPERTY(std::string, derived_type, type, "DodecahedronGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xdodecahedron_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using dodecahedron_geometry = xw::xmaterialize<xdodecahedron_geometry>;

    using dodecahedron_geometry_generator = xw::xgenerator<xdodecahedron_geometry>;

    //
    // dodecahedron_geometry implementation
    //


    template <class D>
    inline void xdodecahedron_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(radius, state, buffers);
        xw::set_patch_from_property(detail, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xdodecahedron_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(radius, patch, buffers);
        xw::set_property_from_patch(detail, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xdodecahedron_geometry<D>::xdodecahedron_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdodecahedron_geometry<D>::set_defaults()
    {
        this->_model_name() = "DodecahedronGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdodecahedron_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xdodecahedron_geometry>;
        extern template xw::xmaterialize<xthree::xdodecahedron_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xdodecahedron_geometry>>;
        extern template class xw::xgenerator<xthree::xdodecahedron_geometry>;
        extern template xw::xgenerator<xthree::xdodecahedron_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xdodecahedron_geometry>>;
    #endif
#endif

#endif