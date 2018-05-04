#ifndef XTHREE_CURVE_HPP
#define XTHREE_CURVE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // curve declaration
    //

    template<class D>
    class xcurve : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xcurve();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using curve = xw::xmaterialize<xcurve>;

    using curve_generator = xw::xgenerator<xcurve>;

    //
    // curve implementation
    //


    template <class D>
    inline void xcurve<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xcurve<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xcurve<D>::xcurve()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcurve<D>::set_defaults()
    {
        this->_model_name() = "CurveModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xcurve>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xcurve>>;
    extern template class xw::xgenerator<xthree::xcurve>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xcurve>>;
#endif

#endif