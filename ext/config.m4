PHP_ARG_ENABLE(phalcon, whether to enable phalcon, [ --enable-phalcon   Enable Phalcon])

if test "$PHP_PHALCON" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, PHALCON_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_PHALCON, 1, [Whether you have Phalcon])
	phalcon_sources="phalcon.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c phalcon/mvc/view/exception.zep.c
	phalcon/annotations/exception.zep.c
	phalcon/mvc/model/exception.zep.c
	phalcon/mvc/view/engine/volt/exception.zep.c
	phalcon/parsers/annotations.zep.c
	phalcon/parsers/orm.zep.c
	phalcon/parsers/uri.zep.c
	phalcon/parsers/volt.zep.c phalcon/annotations/scanner.c
	phalcon/annotations/parser.c
	phalcon/mvc/model/orm.c
	phalcon/mvc/model/query/scanner.c
	phalcon/mvc/model/query/parser.c
	phalcon/mvc/view/engine/volt/parser.c
	phalcon/mvc/view/engine/volt/scanner.c
	phalcon/mvc/url/utils.c"
	PHP_NEW_EXTENSION(phalcon, $phalcon_sources, $ext_shared,, )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "phalcon/annotations phalcon/mvc/model phalcon/mvc/view phalcon/mvc/view/engine/volt phalcon/parsers"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done
	PHP_SUBST(PHALCON_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([phalcon], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/phalcon], [php_PHALCON.h])

fi
