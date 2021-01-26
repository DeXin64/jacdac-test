# Real time clock

    identifier: 0x1a8b1a28
    extends: _sensor

Real time clock to support collecting data with precise time stamps.
## Registers

    ro now @ reading {
        epoch: u32
        year: u16
        month: u8 { absolute_min=1, absolute_max=12 }
        date: u8 { absolute_min=1, absolute_max=31 }
        day: u8 { absolute_min=1, absolute_max=7 }
        hour: u8 { absolute_min=0, absolute_max=23 }
        min: u8 { absolute_min=0, absolute_max=59 }
        sec: u8 { absolute_min=0, absolute_max=59 }
    }

Current time in 24h representation. 
* ``echo`` is the Unix epoch, seconds since ``1/1/1970``
* ``date`` is day of the month, starting at ``1``
* ``day`` is day of the week, starting at ``1`` as monday
Default streaming period is 1 second.

    ro error?: u16.16 s @ 0x180

Time drift since the last call to the ``set_time`` command.

    const precision?: u16.16 ppm @ 0x180

Error on the clock, in parts per million of seconds.

    enum Variant: u8 {
        Computer = 1
        Crystal = 2        
        Cuckoo = 3
    }
    const variant?: Variant @ variant

The type of physical clock used by the sensor.

## Commands

    command set_time @ 0x80 {
        epoch: u32
        year: u16
        month: u8 { absolute_min=1, absolute_max=12 }
        date: u8 { absolute_min=1, absolute_max=31 }
        day: u8 { absolute_min=1, absolute_max=7 }
        hour: u8 { absolute_min=0, absolute_max=23 }
        min: u8 { absolute_min=0, absolute_max=59 }
        sec: u8 { absolute_min=0, absolute_max=59 }
    }

Sets the current time and resets the error.