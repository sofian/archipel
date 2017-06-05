/*
 * gray.cpp
 *
 * (c) 2015 Sofian Audry -- info(@)sofianaudry(.)com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

void arrayBinaryToGray(uint8_t* dst, const uint8_t* src, size_t n)
{

}

void arrayGrayToBinary(uint8_t* dst, const uint8_t* src, size_t n)
{
  if (size > 0) {
    // Copy first bit.
    uint8_t lastBit = arrayBitRead(src, 0);
    arrayBitWrite(dst, 0, lastBit);

    for (int i = 1; i < n; i++)
    {
      // XOR operation
      arrayBitWrite(dst, i, arrayBitRead(src, 0));
      dst

        /* XOR operation */


        if (binary[i] == gray[i+1])

            binary = binary + "0";

        else

            binary = binary + "1";

    }
  }
  binary = gray[0];

  for (int i = 0; i < gray.length() - 1; i++)

  {

      /* XOR operation */

      if (binary[i] == gray[i+1])

          binary = binary + "0";

      else

          binary = binary + "1";

  }
}
