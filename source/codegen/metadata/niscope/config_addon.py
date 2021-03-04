# We need to maintain the version here since it needs to be updated by the build process on GitHub
config_additional_config = {
    'module_version': '1.3.3.dev0',
    'latest_runtime_version_tested_against': '20.0.0',
    'custom_types': [
        # Redundant, since waveform_info is also in the base config.py file. See issue 1495 (https://github.com/ni/nimi-python/issues/1495) 
        {
            'ctypes_type': 'struct_niScope_wfmInfo',
            'file_name': 'waveform_info',
            'python_name': 'WaveformInfo'
        },
        {
            'ctypes_type': 'struct_niScope_coefficientInfo',
            'file_name': 'coefficient_info',
            'python_name': 'CoefficientInfo'
        },
        {
            'ctypes_type': '',
            'file_name': 'measurement_stats',
            'python_name': 'MeasurementStats'
        }
    ]
}
