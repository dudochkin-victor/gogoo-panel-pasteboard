
#ifndef __mnb_pasteboard_marshal_MARSHAL_H__
#define __mnb_pasteboard_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:ENUM (./mnb-pasteboard-marshal.list:1) */
#define mnb_pasteboard_marshal_VOID__ENUM	g_cclosure_marshal_VOID__ENUM

/* VOID:INT64 (./mnb-pasteboard-marshal.list:2) */
extern void mnb_pasteboard_marshal_VOID__INT64 (GClosure     *closure,
                                                GValue       *return_value,
                                                guint         n_param_values,
                                                const GValue *param_values,
                                                gpointer      invocation_hint,
                                                gpointer      marshal_data);

/* VOID:STRING (./mnb-pasteboard-marshal.list:3) */
#define mnb_pasteboard_marshal_VOID__STRING	g_cclosure_marshal_VOID__STRING

/* VOID:VOID (./mnb-pasteboard-marshal.list:4) */
#define mnb_pasteboard_marshal_VOID__VOID	g_cclosure_marshal_VOID__VOID

G_END_DECLS

#endif /* __mnb_pasteboard_marshal_MARSHAL_H__ */

