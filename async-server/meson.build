project(
    'async-websocket-server',
    'cpp',
    default_options: [
        'buildtype=release',
        'optimization=3',
        'strip=true',
        'cpp_std=c++11',
        'b_ndebug=if-release',
        'default_library=static',
    ],
)


deps = []
deps += dependency(
    'oatpp',
    version: '1.3.0',
    default_options: ['tests=disabled'],
)
deps += dependency(
    'oatpp-websocket',
    version: '1.3.0',
    default_options: ['tests=false'],
)


async_websocket_server_lib = library(
    'async-websocket-server',
    files(
        'src/AppComponent.hpp',
        'src/controller/MyController.hpp',
        'src/websocket/WSListener.cpp',
        'src/websocket/WSListener.hpp',
    ),
    include_directories: include_directories('src'),
    dependencies: deps,
    override_options: ['warning_level=3', 'werror=false'],
)


executable(
    'async_websocket_server',
    files('src/App.cpp'),
    include_directories: include_directories('src'),
    dependencies: deps,
    link_with: async_websocket_server_lib,
    override_options: ['warning_level=3', 'werror=false'],
)


if get_option('tests')

    test_deps = deps
    test_deps += dependency('oatpp-test', version: '1.3.0')

    async_websocket_server_test = executable(
        'crud_test',
        files(
            'test/WSTest.cpp',
            'test/WSTest.hpp',
            'test/tests.cpp',
        ),
        include_directories: include_directories('test', 'src'),
        link_with: async_websocket_server_lib,
        dependencies: test_deps,
        override_options: ['warning_level=1', 'werror=false'],
    )
    test('async websocket server tests', async_websocket_server_test)

endif

