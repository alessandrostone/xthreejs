#ifndef XTHREE_AUDIO_ANALYSER_HPP
#define XTHREE_AUDIO_ANALYSER_HPP

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
    // audio_analyser declaration
    //

    template<class D>
    class xaudio_analyser : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xaudio_analyser();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using audio_analyser = xw::xmaterialize<xaudio_analyser>;

    using audio_analyser_generator = xw::xgenerator<xaudio_analyser>;

    //
    // audio_analyser implementation
    //


    template <class D>
    inline void xaudio_analyser<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xaudio_analyser<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xaudio_analyser<D>::xaudio_analyser()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xaudio_analyser<D>::set_defaults()
    {
        this->_model_name() = "AudioAnalyserModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xaudio_analyser>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xaudio_analyser>;
        extern template xw::xmaterialize<xthree::xaudio_analyser>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xaudio_analyser>>;
        extern template class xw::xgenerator<xthree::xaudio_analyser>;
        extern template xw::xgenerator<xthree::xaudio_analyser>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xaudio_analyser>>;
    #endif
#endif

#endif