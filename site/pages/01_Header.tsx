import { Fragment } from 'react'
import { Popover, Transition } from '@headlessui/react'
import { Bars3Icon, XMarkIcon } from '@heroicons/react/24/outline'

const navigation = [
    { name: 'Home', href: '#' },
    { name: 'Documentation', href: '/docs' },
]

export default function Header() {
    return (
        <div className="bg-gray-50">
            <div className="relative overflow-hidden">
                <div className="absolute inset-y-0 h-full w-full" aria-hidden="true">
                    <div className="relative h-full">
                        <svg
                            className="absolute right-full translate-y-1/3 translate-x-1/4 transform sm:translate-x-1/2 md:translate-y-1/2 lg:translate-x-full"
                            width={404}
                            height={784}
                            fill="none"
                            viewBox="0 0 404 784"
                        >
                            <defs>
                                <pattern
                                    id="e229dbec-10e9-49ee-8ec3-0286ca089edf"
                                    x={0}
                                    y={0}
                                    width={20}
                                    height={20}
                                    patternUnits="userSpaceOnUse"
                                >
                                    <rect x={0} y={0} width={4} height={4} className="text-gray-200" fill="currentColor" />
                                </pattern>
                            </defs>
                            <rect width={404} height={784} fill="url(#e229dbec-10e9-49ee-8ec3-0286ca089edf)" />
                        </svg>
                        <svg
                            className="absolute left-full -translate-y-3/4 -translate-x-1/4 transform sm:-translate-x-1/2 md:-translate-y-1/2 lg:-translate-x-3/4"
                            width={404}
                            height={784}
                            fill="none"
                            viewBox="0 0 404 784"
                        >
                            <defs>
                                <pattern
                                    id="d2a68204-c383-44b1-b99f-42ccff4e5365"
                                    x={0}
                                    y={0}
                                    width={20}
                                    height={20}
                                    patternUnits="userSpaceOnUse"
                                >
                                    <rect x={0} y={0} width={4} height={4} className="text-gray-200" fill="currentColor" />
                                </pattern>
                            </defs>
                            <rect width={404} height={784} fill="url(#d2a68204-c383-44b1-b99f-42ccff4e5365)" />
                        </svg>
                    </div>
                </div>

                <div className="relative pt-6 pb-16 sm:pb-24">
                    <Popover>
                        <div className="mx-auto max-w-7xl px-4 sm:px-6">
                            <nav className="relative flex items-center justify-between sm:h-10 md:justify-center" aria-label="Global">
                                <div className="flex flex-1 items-center md:absolute md:inset-y-0 md:left-0">
                                    <div className="flex w-full items-center justify-between md:w-auto">
                                        <a href="#">
                                            <span className="sr-only">Platypus Programming Language</span>
                                            <img
                                                className="h-8 w-auto sm:h-10"
                                                src="/images/logo.png"
                                                alt=""
                                            />
                                        </a>
                                        <div className="-mr-2 flex items-center md:hidden">
                                            <Popover.Button className="inline-flex items-center justify-center rounded-md bg-gray-50 p-2 text-gray-400 hover:bg-gray-100 hover:text-gray-500 focus:outline-none focus:ring-2 focus:ring-inset focus:ring-indigo-500">
                                                <span className="sr-only">Open main menu</span>
                                                <Bars3Icon className="h-6 w-6" aria-hidden="true" />
                                            </Popover.Button>
                                        </div>
                                    </div>
                                </div>
                                <div className="hidden md:flex md:space-x-10">
                                    {navigation.map((item) => (
                                        <a key={item.name} href={item.href} className="font-medium text-gray-500 hover:text-gray-900">
                                            {item.name}
                                        </a>
                                    ))}
                                </div>
                                <div className="hidden md:absolute md:inset-y-0 md:right-0 md:flex md:items-center md:justify-end">
                                    <span className="inline-flex rounded-md shadow">
                                        <a
                                            href="https://github.com/GuanceCloud/platypus"
                                            target="_blank"
                                            rel="noreferrer"
                                            className="inline-flex items-center rounded-md border border-transparent bg-white px-4 py-2 text-base font-medium text-indigo-600 hover:text-indigo-500"
                                        >
                                            View on GitHub
                                        </a>
                                    </span>
                                </div>
                            </nav>
                        </div>

                        <Transition
                            as={Fragment}
                            enter="duration-150 ease-out"
                            enterFrom="opacity-0 scale-95"
                            enterTo="opacity-100 scale-100"
                            leave="duration-100 ease-in"
                            leaveFrom="opacity-100 scale-100"
                            leaveTo="opacity-0 scale-95"
                        >
                            <Popover.Panel
                                focus
                                className="absolute inset-x-0 top-0 z-10 origin-top-right transform p-2 transition md:hidden"
                            >
                                <div className="overflow-hidden rounded-lg bg-white shadow-md ring-1 ring-black ring-opacity-5">
                                    <div className="flex items-center justify-between px-5 pt-4">
                                        <div>
                                            <img
                                                className="h-8 w-auto"
                                                src="/images/logo.png"
                                                alt=""
                                            />
                                        </div>
                                        <div className="-mr-2">
                                            <Popover.Button className="inline-flex items-center justify-center rounded-md bg-white p-2 text-gray-400 hover:bg-gray-100 hover:text-gray-500 focus:outline-none focus:ring-2 focus:ring-inset focus:ring-indigo-500">
                                                <span className="sr-only">Close main menu</span>
                                                <XMarkIcon className="h-6 w-6" aria-hidden="true" />
                                            </Popover.Button>
                                        </div>
                                    </div>
                                    <div className="space-y-1 px-2 pt-2 pb-3">
                                        {navigation.map((item) => (
                                            <a
                                                key={item.name}
                                                href={item.href}
                                                className="block rounded-md px-3 py-2 text-base font-medium text-gray-700 hover:bg-gray-50 hover:text-gray-900"
                                            >
                                                {item.name}
                                            </a>
                                        ))}
                                    </div>
                                    <a
                                        href="https://github.com/GuanceCloud/platypus"
                                        target="_blank"
                                        rel="noreferrer"
                                        className="block w-full bg-gray-50 px-5 py-3 text-center font-medium text-indigo-600 hover:bg-gray-100 hover:text-indigo-700"
                                    >
                                        View on GitHub
                                    </a>
                                </div>
                            </Popover.Panel>
                        </Transition>
                    </Popover>

                    <div className="mx-auto mt-16 max-w-7xl px-4 sm:mt-24 sm:px-6">
                        <div className="text-center">
                            <h1 className="text-4xl font-bold tracking-tight text-gray-900 sm:text-5xl md:text-6xl">
                                <span className="block">Platypus Programming Language</span>
                            </h1>
                            <p className="mx-auto h-12 mt-3 max-w-md text-base text-gray-500 sm:text-lg md:mt-5 md:max-w-3xl md:text-xl">
                                Platypus is a programming language for <span className="text-indigo-500 font-bold">Observability Data Pipeline</span>
                            </p>
                            <div className="mt-8 flex gap-x-4 sm:justify-center">
                                <a
                                    href="https://platypus.guance.io/docs"
                                    target="_blank" rel="noreferrer"
                                    className="inline-block rounded-lg bg-indigo-600 px-4 py-1.5 text-base font-semibold leading-7 text-white shadow-sm ring-1 ring-indigo-600 hover:bg-indigo-700 hover:ring-indigo-700"
                                >
                                    Get started<span className="text-indigo-200" aria-hidden="true">→</span>
                                </a>
                                <a
                                    href="https://github.com/GuanceCloud/platypus" target="_blank" rel="noreferrer"
                                    className="inline-block rounded-lg px-4 py-1.5 text-base font-semibold leading-7 text-gray-900 ring-1 ring-gray-900/10 hover:ring-gray-900/20">
                                    GitHub <span className="text-gray-400" aria-hidden="true">→</span>
                                </a>
                            </div>
                            {/* <p className="mx-auto mt-3 max-w-md text-base text-gray-500 sm:text-lg md:mt-5 md:max-w-3xl md:text-xl">
                Anim aute id magna aliqua ad ad non deserunt sunt. Qui irure qui lorem cupidatat commodo. Elit sunt amet
                fugiat veniam occaecat fugiat aliqua.
              </p> */}
                        </div>
                    </div>
                </div>

                <div className="relative">
                    <div className="absolute inset-0 flex flex-col" aria-hidden="true">
                        <div className="flex-1" />
                        <div className="w-full flex-1 bg-gray-800" />
                    </div>
                    <div className="mx-auto max-w-7xl px-4 sm:px-6">
                        {/* <img
                            className="relative rounded-lg shadow-lg"
                            src="https://tailwindui.com/img/component-images/top-nav-with-multi-column-layout-screenshot.jpg"
                            alt="App screenshot"
                        /> */}
                    </div>
                </div>
            </div>
            <div className="bg-gray-800">
                <div className="mx-auto max-w-7xl py-16 px-4 sm:py-24 sm:px-6 lg:px-8">
                    <h2 className="text-center text-base font-semibold text-gray-400">
                        Trusted by popular platforms and tools about observability
                    </h2>
                    <div className="mt-8 grid grid-cols-1 gap-8 md:grid-cols-1 lg:grid-cols-1">
                        <div className="col-span-1 flex justify-center md:col-span-2 lg:col-span-1">
                            <img className="h-12" src="/images/guance.png" alt="Tuple" />
                        </div>
                    </div>
                </div>
            </div>
        </div>
    )
}
