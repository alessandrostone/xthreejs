#ifndef XTHREE_LENS_FLARE_HPP
#define XTHREE_LENS_FLARE_HPP

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
    // lens_flare declaration
    //

    template<class D>
    class xlens_flare : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xlens_flare();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using lens_flare = xw::xmaterialize<xlens_flare>;

    using lens_flare_generator = xw::xgenerator<xlens_flare>;

    //
    // lens_flare implementation
    //


    template <class D>
    inline void xlens_flare<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xlens_flare<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xlens_flare<D>::xlens_flare()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlens_flare<D>::set_defaults()
    {
        this->_model_name() = "LensFlareModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xlens_flare>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xlens_flare>;
        extern template xw::xmaterialize<xthree::xlens_flare>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xlens_flare>>;
        extern template class xw::xgenerator<xthree::xlens_flare>;
        extern template xw::xgenerator<xthree::xlens_flare>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xlens_flare>>;
    #endif
#endif

#endif