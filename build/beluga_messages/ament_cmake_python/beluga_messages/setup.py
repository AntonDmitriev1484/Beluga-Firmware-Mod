from setuptools import find_packages
from setuptools import setup

setup(
    name='beluga_messages',
    version='0.0.0',
    packages=find_packages(
        include=('beluga_messages', 'beluga_messages.*')),
)
