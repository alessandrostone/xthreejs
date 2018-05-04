#ifndef XTHREE_CAMERA_HPP
#define XTHREE_CAMERA_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // camera declaration
    //

    template<class D>
    class xcamera : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(matrix4, derived_type, matrixWorldInverse, matrix4({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}));
        XPROPERTY(matrix4, derived_type, projectionMatrix, matrix4({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}));


    protected:

        xcamera();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using camera = xw::xmaterialize<xcamera>;

    using camera_generator = xw::xgenerator<xcamera>;

    //
    // camera implementation
    //


    template <class D>
    inline void xcamera<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(matrixWorldInverse, state, buffers);
        xw::set_patch_from_property(projectionMatrix, state, buffers);
    }

    template <class D>
    inline void xcamera<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(matrixWorldInverse, patch, buffers);
        xw::set_property_from_patch(projectionMatrix, patch, buffers);
    }

    template <class D>
    inline xcamera<D>::xcamera()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcamera<D>::set_defaults()
    {
        this->_model_name() = "CameraModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xcamera>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xcamera>>;
    extern template class xw::xgenerator<xthree::xcamera>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xcamera>>;
#endif

#endif