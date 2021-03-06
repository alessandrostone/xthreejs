#ifndef XTHREE_BOX2_HPP
#define XTHREE_BOX2_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // box2 declaration
    //

    template<class D>
    class xbox2 : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector2, derived_type, min, vector2({0,0}));
        XPROPERTY(vector2, derived_type, max, vector2({0,0}));


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xbox2();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using box2 = xw::xmaterialize<xbox2>;

    using box2_generator = xw::xgenerator<xbox2>;

    //
    // box2 implementation
    //


    template <class D>
    inline void xbox2<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(min, state, buffers);
        xw::set_patch_from_property(max, state, buffers);
    }

    template <class D>
    inline void xbox2<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(min, patch, buffers);
        xw::set_property_from_patch(max, patch, buffers);
    }

    template <class D>
    inline xbox2<D>::xbox2()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbox2<D>::set_defaults()
    {
        this->_model_name() = "Box2Model";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xbox2>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xbox2>;
        extern template xw::xmaterialize<xthree::xbox2>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xbox2>>;
        extern template class xw::xgenerator<xthree::xbox2>;
        extern template xw::xgenerator<xthree::xbox2>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xbox2>>;
    #endif
#endif

#endif