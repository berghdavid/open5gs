# Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>

# This file is part of Open5GS.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

libasn1c_common_cc_flags = [
    '-DASN_DISABLE_BER_SUPPORT',
    '-DASN_DISABLE_XER_SUPPORT',
    '-DASN_DISABLE_OER_SUPPORT',
    '-DASN_DISABLE_UPER_SUPPORT',
    '-DASN_DISABLE_JER_SUPPORT',
]
libasn1c_common_cc_flags += cc.get_supported_arguments([
    '-w', '-std=gnu99',
])

subdir('gen')
subdir('util')
