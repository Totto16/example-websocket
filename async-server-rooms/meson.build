project(
    'async-server-rooms',
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


async_server_rooms_lib = library(
    'async-server-rooms',
    files(
        'src/AppComponent.hpp',
        'src/controller/RoomsController.hpp',
        'src/rooms/Lobby.cpp',
        'src/rooms/Lobby.hpp',
        'src/rooms/Peer.cpp',
        'src/rooms/Peer.hpp',
        'src/rooms/Room.cpp',
        'src/rooms/Room.hpp',
    ),
    include_directories: include_directories('src'),
    dependencies: deps,
    override_options: ['warning_level=3', 'werror=false'],
)


executable(
    'async_server_rooms',
    files('src/App.cpp'),
    include_directories: include_directories('src'),
    dependencies: deps,
    link_with: async_server_rooms_lib,
    override_options: ['warning_level=3', 'werror=false'],
)


if get_option('tests')

    test_deps = deps
    test_deps += dependency('oatpp-test', version: '1.3.0')

    async_server_rooms_test = executable(
        'async_server_rooms_test',
        files(
            'test/WSTest.cpp',
            'test/WSTest.hpp',
            'test/tests.cpp',
        ),
        include_directories: include_directories('test', 'src'),
        link_with: async_server_rooms_lib,
        dependencies: test_deps,
        override_options: ['warning_level=1', 'werror=false'],
    )
    test('async server rooms tests', async_server_rooms_test)

endif

