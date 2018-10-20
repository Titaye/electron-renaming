{
  "target_defaults": {
    "msbuild_toolset": "v141"
  },
  "targets": [
    {
      "target_name": "testnative",
      "msbuild_settings": {
          "Link": {
              "ImageHasSafeExceptionHandlers": "false"
          }
      },
      "sources": [
        "test.cpp"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}